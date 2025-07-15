void __thiscall CProfileNode::~CProfileNode(CProfileNode *this)
{
  CProfileNode *Child; // edi
  CProfileNode *Sibling; // esi

  Child = this->Child;
  if ( Child )
  {
    CProfileNode::~CProfileNode(this->Child);
    operator delete(Child);
  }
  Sibling = this->Sibling;
  if ( Sibling )
  {
    CProfileNode::~CProfileNode(Sibling);
    operator delete(Sibling);
  }
}
