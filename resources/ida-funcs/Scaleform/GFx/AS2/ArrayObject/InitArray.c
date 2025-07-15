void __thiscall Scaleform::GFx::AS2::ArrayObject::InitArray(
        Scaleform::GFx::AS2::ArrayObject *this,
        const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v2; // esi
  int v3; // ebp
  bool v4; // cc
  Scaleform::GFx::AS2::Environment *Env; // ecx
  int FirstArgBottomIndex; // eax
  unsigned int v7; // eax
  unsigned int v8; // edx
  int v9; // edi
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // [esp+10h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::ObjectInterface *v12; // [esp+14h] [ebp-14h]
  Scaleform::GFx::AS2::Value v13; // [esp+18h] [ebp-10h] BYREF

  v2 = fn;
  v3 = 0;
  v4 = fn->NArgs <= 0;
  v13.T.Type = 0;
  if ( !v4 )
  {
    v12 = &this->Scaleform::GFx::AS2::ObjectInterface;
    do
    {
      if ( v13.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v13);
      Env = v2->Env;
      FirstArgBottomIndex = v2->FirstArgBottomIndex;
      LOBYTE(fn) = 0;
      v7 = FirstArgBottomIndex - v3;
      v8 = 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart;
      v9 = 0;
      v13.T.Type = 4;
      v13.NV.Int32Value = v3;
      if ( v7 <= v8 )
        v9 = (int)&Env->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      Scaleform::GFx::AS2::Value::ToStringImpl(&v13, (Scaleform::GFx::ASString *)&v11, Env, -1, 0);
      v12->SetMember(
        v12,
        v2->Env,
        (const Scaleform::GFx::ASString *)&v11,
        (const Scaleform::GFx::AS2::Value *)v9,
        (const Scaleform::GFx::AS2::PropFlags *)&fn);
      v10 = v11;
      --v11->RefCount;
      if ( !v10->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      ++v3;
    }
    while ( v3 < v2->NArgs );
  }
}
