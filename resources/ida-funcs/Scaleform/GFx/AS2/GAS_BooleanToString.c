void __cdecl Scaleform::GFx::AS2::GAS_BooleanToString(Scaleform::GFx::ASStringNode *fn)
{
  Scaleform::GFx::ASStringNode *v1; // esi
  Scaleform::GFx::ASStringNode *pLower; // eax
  $7DDA6D7E09E348E44B226E8441B9AFBF *v3; // ecx
  Scaleform::GFx::AS2::Environment *pData; // edi
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Value *pManager; // esi
  Scaleform::GFx::ASStringNode *v7; // ecx
  bool v8; // zf
  Scaleform::GFx::AS2::Value v9; // [esp+4h] [ebp-10h] BYREF

  v1 = fn;
  if ( fn->pLower
    && (*((int (__thiscall **)(Scaleform::GFx::ASStringNode *))fn->pLower->$7DDA6D7E09E348E44B226E8441B9AFBF::pData + 2))(fn->pLower) == 10 )
  {
    pLower = v1->pLower;
    if ( pLower )
      v3 = &pLower[-1].8;
    else
      v3 = 0;
    pData = (Scaleform::GFx::AS2::Environment *)v1[1].pData;
    v5 = (Scaleform::GFx::AS2::Value *)((int (__thiscall *)($7DDA6D7E09E348E44B226E8441B9AFBF *, Scaleform::GFx::AS2::Value *))v3->pLower->HashFlags)(
                                         v3,
                                         &v9);
    Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&fn, pData, -1, 0);
    pManager = (Scaleform::GFx::AS2::Value *)v1->pManager;
    if ( pManager->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pManager);
    v7 = fn;
    pManager->T.Type = 5;
    pManager->NV.Int32Value = (int)v7;
    v8 = ++v7->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    if ( v9.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v9);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      (Scaleform::GFx::AS2::Environment *)v1[1].pData,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Boolean");
  }
}
