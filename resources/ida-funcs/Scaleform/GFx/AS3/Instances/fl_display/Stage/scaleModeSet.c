void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::scaleModeSet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  void (__thiscall *v4)(Scaleform::GFx::AS3::VM *); // edi
  int v5; // eax

  pNode = value->pNode;
  ++pNode->RefCount;
  v4 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  v5 = Scaleform::String::CompareNoCase((char *)pNode->pData, "noScale");
  if ( v5 )
  {
    if ( Scaleform::String::CompareNoCase((char *)pNode->pData, "exactFit") )
      v5 = Scaleform::String::CompareNoCase((char *)pNode->pData, "noBorder") != 0 ? 1 : 3;
    else
      v5 = 2;
  }
  if ( v4 )
    (*(void (__thiscall **)(void (__thiscall *)(Scaleform::GFx::AS3::VM *), int))(*(_DWORD *)v4 + 52))(v4, v5);
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
