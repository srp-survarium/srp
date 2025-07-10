void __thiscall Scaleform::GFx::DisplayObject::SetOriginalName(
        Scaleform::GFx::DisplayObject *this,
        const Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::CharacterHandle *pObject; // edi
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v5; // ecx

  Scaleform::GFx::DisplayObject::SetName(this, (int)name);
  pObject = this->pNameHandle.pObject;
  if ( pObject || (pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(this)) != 0 )
  {
    pNode = name->pNode;
    ++name->pNode->RefCount;
    v5 = pObject->OriginalName.pNode;
    if ( v5->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    pObject->OriginalName.pNode = pNode;
  }
}
