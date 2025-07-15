void __userpurge CProfileNode::CProfileNode(
        CProfileNode *this@<ecx>,
        int a2@<eax>,
        CProfileNode *name,
        CProfileNode *parent)
{
  *(_DWORD *)a2 = this;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 20) = name;
  CProfileNode::Reset((CProfileNode *)a2);
}
