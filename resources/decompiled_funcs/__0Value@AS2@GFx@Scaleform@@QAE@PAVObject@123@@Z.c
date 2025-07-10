void __thiscall Scaleform::GFx::AS2::Value::Value(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Object *pobj)
{
  Scaleform::GFx::AS2::FunctionRef *v3; // eax
  int Function; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // edx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // ecx
  unsigned int v8; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // [esp+10h] [ebp-8h]
  char v12; // [esp+14h] [ebp-4h]

  if ( pobj && pobj->GetObjectType(&pobj->Scaleform::GFx::AS2::ObjectInterface) == Object_Function )
  {
    this->T.Type = 8;
    v3 = pobj->ToFunction(&pobj->Scaleform::GFx::AS2::ObjectInterface, &v10);
    this->V.FunctionValue.Flags = 0;
    Function = (int)v3->Function;
    this->NV.Int32Value = (int)v3->Function;
    if ( Function )
      *(_DWORD *)(Function + 12) = (*(_DWORD *)(Function + 12) + 1) & 0x8FFFFFFF;
    this->V.FunctionValue.pLocalFrame = 0;
    pLocalFrame = v3->pLocalFrame;
    if ( pLocalFrame )
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&this->V.FunctionValue, pLocalFrame, v3->Flags & 1);
    if ( (v12 & 2) == 0 )
    {
      if ( v10 )
      {
        RefCount = v10->RefCount;
        v7 = v10;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          v10->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
        }
      }
    }
    v10 = 0;
    if ( (v12 & 1) == 0 && v11 )
    {
      v8 = v11->RefCount;
      v9 = v11;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v8) != 0 )
      {
        v11->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
  }
  else
  {
    this->T.Type = 6;
    this->NV.Int32Value = (int)pobj;
    if ( pobj )
      pobj->RefCount = (pobj->RefCount + 1) & 0x8FFFFFFF;
  }
}
