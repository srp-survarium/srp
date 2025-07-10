void __thiscall CProfileNode::Reset(CProfileNode *this)
{
  CProfileNode *Child; // ecx

  do
  {
    Child = this->Child;
    this->TotalCalls = 0;
    this->TotalTime = 0.0;
    if ( Child )
      CProfileNode::Reset(Child);
    this = this->Sibling;
  }
  while ( this );
}
