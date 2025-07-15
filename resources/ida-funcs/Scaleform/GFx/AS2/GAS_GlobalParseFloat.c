void __cdecl Scaleform::GFx::AS2::GAS_GlobalParseFloat(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // ebx
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Value *v3; // ecx
  Scaleform::GFx::ASStringNode *v4; // esi
  const Scaleform::GFx::AS2::FnCall *v5; // edi
  long double v6; // st7
  Scaleform::GFx::AS2::Value *Result; // edi
  long double v8; // st7
  long double v10; // [esp+4h] [ebp-8h] BYREF

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    v3 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v3 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    Scaleform::GFx::AS2::Value::ToStringImpl(v3, (Scaleform::GFx::ASString *)&v10, Env, -1, 0);
    v4 = (Scaleform::GFx::ASStringNode *)LODWORD(v10);
    v5 = *(const Scaleform::GFx::AS2::FnCall **)LODWORD(v10);
    fn = 0;
    v6 = Scaleform::SFstrtod((int)v5, (char *)*(_DWORD *)LODWORD(v10), (char **)&fn);
    if ( v5 == fn )
      v6 = Scaleform::GFx::NumberUtil::NaN();
    Result = v1->Result;
    v10 = v6;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    v8 = v10;
    Result->T.Type = 3;
    Result->NV.NumberValue = v8;
    if ( v4->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  }
}
