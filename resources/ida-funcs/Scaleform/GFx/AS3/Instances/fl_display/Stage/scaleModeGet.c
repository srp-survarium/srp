void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::scaleModeGet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        Scaleform::GFx::ASString *result)
{
  void (__thiscall *v3)(Scaleform::GFx::AS3::VM *); // ecx
  int v4; // eax
  int v5; // eax
  char *v6; // edx
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+8h] [ebp-4h] BYREF

  v3 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  v4 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v3 + 56))(v3);
  if ( v4 )
  {
    v5 = v4 - 2;
    if ( v5 )
    {
      if ( v5 == 1 )
        v6 = "noBorder";
      else
        v6 = "showAll";
    }
    else
    {
      v6 = "exactFit";
    }
  }
  else
  {
    v6 = "noScale";
  }
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                      v6,
                      strlen(v6),
                      0);
  ++ConstStringNode->RefCount;
  Scaleform::GFx::ASString::Append(result, (Scaleform::GFx::ASStringNode *)&ConstStringNode);
  v7 = ConstStringNode;
  --ConstStringNode->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}
