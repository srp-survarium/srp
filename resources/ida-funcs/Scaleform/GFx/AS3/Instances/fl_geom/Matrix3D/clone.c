void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::clone(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Value *v3; // eax
  int i; // ecx
  Scaleform::GFx::AS3::Value *v5; // esi
  Scaleform::Render::Matrix4x4<double> *p_mat4; // edi
  int v7; // ebx
  unsigned int Flags; // eax
  char v9; // cl
  unsigned int v10; // edx
  Scaleform::GFx::AS3::Value *v11; // esi
  int j; // edi
  unsigned int v13; // eax
  Scaleform::GFx::AS3::CheckResult v14; // [esp+13h] [ebp-10Dh] BYREF
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *v15; // [esp+14h] [ebp-10Ch]
  long double v16; // [esp+18h] [ebp-108h]
  Scaleform::GFx::AS3::Value args[16]; // [esp+20h] [ebp-100h] BYREF
  char vars0; // [esp+120h] [ebp+0h] BYREF

  v15 = this;
  v3 = args;
  for ( i = 15; i >= 0; --i )
  {
    v3->Flags = 0;
    v3->Bonus.pWeakProxy = 0;
    ++v3;
  }
  v5 = args;
  p_mat4 = &this->mat4;
  v7 = 16;
  do
  {
    Flags = v5->Flags;
    v9 = v5->Flags;
    v16 = p_mat4->M[0][0];
    if ( (v9 & 0x1Fu) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v5);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v5);
    }
    v10 = v5->Flags & 0xFFFFFFE4;
    v5->value.VNumber = v16;
    v5->Flags = v10 | 4;
    p_mat4 = (Scaleform::Render::Matrix4x4<double> *)((char *)p_mat4 + 8);
    ++v5;
    --v7;
  }
  while ( v7 );
  Scaleform::GFx::AS3::VM::constructBuiltinObject(
    v15->pTraits.pObject->pVM,
    &v14,
    result,
    "flash.geom.Matrix3D",
    0x10u,
    args);
  v11 = (Scaleform::GFx::AS3::Value *)&vars0;
  for ( j = 15; j >= 0; --j )
  {
    v13 = v11[-1].Flags;
    --v11;
    if ( (v13 & 0x1F) > 9 )
    {
      if ( (v13 & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v11);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v11);
    }
  }
}
