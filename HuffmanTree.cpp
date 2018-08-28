#include "HuffmanTree.h"

#include <queue>
using std::priority_queue;

using std::vector;
using std::string;

HuffmanTree::HuffmanTree(HuffmanNode* p)
	: root(p)
{
	// ��ָ��p�Ը������й���
}

void HuffmanTree::CodingAll(HuffmanNode* p, const string& prefix)
{
	// ��p��ΪNULL��ݹ����pΪ�����������н����б���
	if (p != NULL)
	{
		// ���p������������ǰ׺��prefix��0
		CodingAll(p->lChild, prefix + "0");
		// ���p������������ǰ׺��prefix��1
		CodingAll(p->rChild, prefix + "1");
		// Ҷ�ӽ����Ϊ��Ȼ��, �Դ˶Ա���������Ӧλ�ø�����prefix.
		if (p->number < HC.size())
			HC[p->number] = prefix;
	}
}

void HuffmanTree::HuffmanCoding(const vector<double>& P, vector<string>& C)
{
	// ��������HC�ĳ�������Ϊ���������ĳ���.
	HC.resize(P.size());
	// �洢Huffman������С���ȼ�����PQ, ���ȼ�Ϊ����Ȩֵ, 
	// ʵ�ʴ洢�������ĸ����ָ��. 
	priority_queue<HuffmanNode*,
		vector<HuffmanNode*>, greater_HuffmanNodePointer> PQ;
	// һ���Ը��������ڱ����л���ֵĽ��
	vector<HuffmanNode> data (2 * P.size() - 1);
	// index��Ϊ���, ָʾ��ǰ��ʹ��data[index]���Ľ��.
	size_t index;		// ע���������򲻽����������forѭ��.
	// ��ʼ����n�����и�������
	for (index = 0; index < P.size(); index++)
	{
		// ��Ӧ�����ķ���, ���Ϊ��Ȼ��.
		data[index].number = index;
		// ���Ȩֵ���ո���������ֵ
		data[index].weight = P[index];
		data[index].lChild = NULL;
		data[index].rChild = NULL;
		// �������ȼ�������
		PQ.push(&data[index]);
	}
	// ѭ�������Թ���Huffman��
	while (PQ.size() > 1)
	{
		// ȡ�½������
		HuffmanNode* p = &data[index];
		// �³��ֵĽ����ͳһΪHC.size()
		p->number = HC.size();
		// �����ȼ������е���СԪ��Ϊp������
		p->weight = PQ.top()->weight;
		p->lChild = PQ.top();
		// ȡ����СԪ
		PQ.pop();
		// �����ȼ������е���СԪ��Ϊp���Һ���
		p->weight += PQ.top()->weight;
		p->rChild = PQ.top();
		// ȡ����СԪ
		PQ.pop();
		// ���µ����������ȼ�����
		PQ.push(p);
		// ��Ÿ���, �´�ʹ���½��.
		index++;
	}
	// ��PQ������ɸ���������ʣ��ΨһHuffman�����б���
	if (!PQ.empty())
	{
		CodingAll(PQ.top(), "");
		C = HC;		// �����ձ��븴�Ƹ�C
	}
}