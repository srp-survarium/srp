void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::nameGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *v4; // edi
  Scaleform::GFx::ASStringNode *p_NullStringNode; // esi
  Scaleform::GFx::ASStringNode *v6; // ecx
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASString v9; // [esp+8h] [ebp-4h] BYREF

  Scaleform::GFx::DisplayObject::GetName(this->pDispObj.pObject, &v9);
  pNode = v9.pNode;
  if ( v9.pNode->Size || (this->pDispObj.pObject->Flags & 2) == 0 )
  {
    ++v9.pNode->RefCount;
    v4 = result;
    p_NullStringNode = pNode;
  }
  else
  {
    v4 = result;
    p_NullStringNode = &result->pNode->pManager->NullStringNode;
    ++result->pNode->pManager->NullStringNode.RefCount;
  }
  v6 = v4->pNode;
  if ( v4->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  v8 = v9.pNode;
  v4->pNode = p_NullStringNode;
  if ( !--v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}
