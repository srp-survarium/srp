void __thiscall Scaleform::GFx::AS2::Value::SetAsObject(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Object *obj)
{
  Scaleform::GFx::AS2::FunctionRef *v3; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // ecx
  unsigned int v6; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // [esp+10h] [ebp-8h]
  char v10; // [esp+14h] [ebp-4h]

  if ( obj && obj->GetObjectType(&obj->Scaleform::GFx::AS2::ObjectInterface) == Object_Function )
  {
    v3 = obj->ToFunction(&obj->Scaleform::GFx::AS2::ObjectInterface, &v8);
    Scaleform::GFx::AS2::Value::SetAsFunction(this, v3);
    if ( (v10 & 2) == 0 )
    {
      if ( v8 )
      {
        RefCount = v8->RefCount;
        v5 = v8;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          v8->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
        }
      }
    }
    v8 = 0;
    if ( (v10 & 1) == 0 && v9 )
    {
      v6 = v9->RefCount;
      v7 = v9;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v6) != 0 )
      {
        v9->RefCount = v6 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
      }
    }
  }
  else if ( this->T.Type != 6 || this->V.pObjectValue != obj )
  {
    Scaleform::GFx::AS2::Value::DropRefs(this);
    this->T.Type = 6;
    this->NV.Int32Value = (int)obj;
    if ( obj )
      obj->RefCount = (obj->RefCount + 1) & 0x8FFFFFFF;
  }
}
