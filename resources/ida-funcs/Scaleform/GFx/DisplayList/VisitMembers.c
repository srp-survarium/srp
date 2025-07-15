void __thiscall Scaleform::GFx::DisplayList::VisitMembers(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayList::MemberVisitor *pvisitor)
{
  Scaleform::GFx::DisplayList::MemberVisitor *v2; // ebx
  int v3; // edi
  unsigned int Size; // ebp
  Scaleform::GFx::DisplayObjectBase *pCharacter; // esi
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::DisplayList *v7; // [esp+0h] [ebp-4h]

  v7 = this;
  if ( this->DisplayObjectArray.Data.Size )
  {
    v2 = pvisitor;
    v3 = 0;
    Size = this->DisplayObjectArray.Data.Size;
    while ( 1 )
    {
      pCharacter = this->DisplayObjectArray.Data.Data[v3].pCharacter;
      if ( SLOBYTE(pCharacter->Flags) < 0 )
      {
        Scaleform::GFx::DisplayObject::GetName(
          (Scaleform::GFx::DisplayObject *)pCharacter,
          (Scaleform::GFx::ASString *)&pvisitor);
        v6 = (Scaleform::GFx::ASStringNode *)pvisitor;
        if ( pvisitor[5].__vftable )
        {
          v2->Visit(v2, (const Scaleform::GFx::ASString *)&pvisitor, (Scaleform::GFx::InteractiveObject *)pCharacter);
          v6 = (Scaleform::GFx::ASStringNode *)pvisitor;
        }
        if ( !--v6->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v6);
      }
      ++v3;
      if ( !--Size )
        break;
      this = v7;
    }
  }
}
