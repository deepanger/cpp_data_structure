#include <stdio.h>
#include <string.h>
#define MAX 201      /* ႆさ͡ᰯ๖䪮Ꮥͩ 200 */
int d[MAX][MAX];     /* d[i][j] 㶗⹩Ꮎ݆ Xi ঻ Yj ⮳ᰯ䪮ڠڛၿᎾ݆⮳䪮Ꮥ */
char x[MAX], y[MAX]; /* ႆさ͡ᱚᅭ᰸͙ '0' */
void lcs(const char *x, const int m, const char *y, const int n)
{
    int i, j;
    for (i = 0; i <= m; i++)
        d[i][0] = 0; /* 䓨⩻*/
    for (j = 0; j <= n; j++)
        d[0][j] = 0;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else
            {
                d[i][j] = d[i - 1][j] > d[i][j - 1] ? d[i - 1][j] : d[i][j - 1];
            }
        }
    }
}
void lcs_extend(const char *x, const int m, const char *y, const int n);
void lcs_print(const char *x, const int m, const char *y, const int n);
int main()
{
    /* while (scanf ("%s%s", a, b)) { /* TLE */
    /* while (scanf ("%s%s", a, b) == 2) { /* AC */
    while (scanf("%s%s", x, y) != EOF)
    { /* AC */
        const int lx = strlen(x);
        const int ly = strlen(y);
        lcs(x, lx, y, ly);
        printf("%d\n", d[lx][ly]);
        /*
lcs_extend(x, lx, y, ly);
lcs_print(x, lx, y, ly);
printf("\n"); */
    }
    return 0;
}
int p[MAX][MAX]; /* p[i][j] 䃟ᒄ d[i][j] ᭞⩠ਙ͙ၿ䬝䷇ᓆ*/
void lcs_extend(const char *x, const int m, const char *y, const int n)
{
    int i, j;
    memset(p, 0, sizeof(p));
    for (i = 0; i <= m; i++)
        d[i][0] = 0; /* 䓨⩻*/
    for (j = 0; j <= n; j++)
        d[0][j] = 0;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                d[i][j] = d[i - 1][j - 1] + 1;
                p[i][j] = 1;
            }
            else
            {
                if (d[i - 1][j] >= d[i][j - 1])
                {
                    d[i][j] = d[i - 1][j];
                    p[i][j] = 2;
                }
                else
                {
                    d[i][j] = d[i][j - 1];
                    p[i][j] = 3;
                }
            }
        }
    }
}
void lcs_print(const char *x, const int m, const char *y, const int n)
{
    //这里的打印非常有意思，只有mn相等的时候才打印，否则就追溯上一个，因为字母并不相等
    if (m == 0 || n == 0)
        return;
    if (p[m][n] == 1)
    {
        lcs_print(x, m - 1, y, n - 1);
        printf("%c", x[m - 1]);
    }
    else if (p[m][n] == 2)
    {
        lcs_print(x, m - 1, y, n);
    }
    else
    {
        lcs_print(x, m, y, n - 1);
    }
}