void __cdecl Scaleform::GFx::AS2::BitmapDataCtorFunction::LoadBitmapA(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v4; // ecx
  Scaleform::GFx::AS2::BitmapData *v5; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx

  v1 = fn;
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 1;
  if ( v1->NArgs >= 1 )
  {
    Env = v1->Env;
    v4 = 0;
    if ( v1->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v4 = &Env->Stack.Pages.Data.Data[(unsigned int)v1->FirstArgBottomIndex >> 5]->Values[v1->FirstArgBottomIndex
                                                                                         & 0x1F];
    Scaleform::GFx::AS2::Value::ToStringImpl(v4, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
    v5 = Scaleform::GFx::AS2::GFx_LoadBitmap<Scaleform::GFx::ASString>(v1->Env, (const Scaleform::GFx::ASString *)&fn);
    v6 = v5;
    if ( v5 )
    {
      Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v5);
      RefCount = v6->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v6->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
      }
    }
    v8 = (Scaleform::GFx::ASStringNode *)fn;
    if ( fn->ThisFunctionRef.Function-- == (Scaleform::GFx::AS2::FunctionObject *)1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
}
