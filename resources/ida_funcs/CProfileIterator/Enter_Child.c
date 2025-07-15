void __usercall CProfileIterator::Enter_Child(CProfileIterator *this@<eax>, int index@<edx>)
{
  CProfileNode *Child; // ecx
  CProfileNode *Sibling; // ecx
  CProfileNode *CurrentChild; // ecx

  Child = this->CurrentParent->Child;
  this->CurrentChild = Child;
  if ( Child )
  {
    do
    {
      if ( !index )
        break;
      Sibling = this->CurrentChild->Sibling;
      --index;
      this->CurrentChild = Sibling;
    }
    while ( Sibling );
  }
  CurrentChild = this->CurrentChild;
  if ( CurrentChild )
  {
    this->CurrentParent = CurrentChild;
    this->CurrentChild = CurrentChild->Child;
  }
}
