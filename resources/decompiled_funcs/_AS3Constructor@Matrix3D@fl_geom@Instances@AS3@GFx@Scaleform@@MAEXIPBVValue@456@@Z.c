void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  char v3; // bl
  long double *v5; // eax
  Scaleform::GFx::AS3::Value::VU *p_value; // ecx
  int v7; // edx
  Scaleform::GFx::ASStringNode *pNode; // eax
  signed int v9; // esi
  Scaleform::GFx::AS3::VectorBase<double> *v10; // ebx
  Scaleform::Render::Matrix4x4<double> *p_mat4; // edi
  __int16 Flags; // ax
  Scaleform::Render::Matrix4x4<double> *v13; // esi
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *v14; // edi
  char v15; // [esp+B7h] [ebp-79h]
  Scaleform::GFx::ASString v16; // [esp+B8h] [ebp-78h] BYREF
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *v17; // [esp+BCh] [ebp-74h]
  Scaleform::GFx::AS3::Value v18; // [esp+C0h] [ebp-70h] BYREF
  Scaleform::Render::Matrix3x4<float> result; // [esp+D0h] [ebp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+100h] [ebp-30h] BYREF

  v3 = 0;
  v17 = this;
  v16.pNode = 0;
  if ( argc == 16 )
  {
    v5 = &this->mat4.M[0][1];
    p_value = &argv[1].value;
    v7 = 2;
    do
    {
      v5 += 8;
      *(v5 - 9) = p_value[-2].VNumber;
      p_value += 16;
      --v7;
      *(v5 - 8) = p_value[-16].VNumber;
      *(v5 - 7) = p_value[-14].VNumber;
      *(v5 - 6) = p_value[-12].VNumber;
      *(v5 - 5) = p_value[-10].VNumber;
      *(v5 - 4) = p_value[-8].VNumber;
      *(v5 - 3) = p_value[-6].VNumber;
      *(v5 - 2) = p_value[-4].VNumber;
    }
    while ( v7 );
  }
  else if ( argc == 1 )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3
      || (v3 = 1,
          (*(void (__thiscall **)(_DWORD, Scaleform::GFx::ASString *))(**(_DWORD **)(argv->value.VS._1.VInt + 20) + 16))(
            *(_DWORD *)(argv->value.VS._1.VInt + 20),
            &v16),
          v15 = 0,
          !Scaleform::GFx::ASString::operator==(&v16, "Vector$double")) )
    {
      v15 = 1;
    }
    if ( (v3 & 1) != 0 )
    {
      pNode = v16.pNode;
      --v16.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    if ( !v15 )
    {
      v9 = 0;
      v10 = (Scaleform::GFx::AS3::VectorBase<double> *)(argv->value.VS._1.VInt + 32);
      p_mat4 = &this->mat4;
      do
      {
        v18.Flags = 0;
        v18.Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::VectorBase<double>::Get(v10, v9, &v18);
        Flags = v18.Flags;
        p_mat4->M[0][0] = v18.value.VNumber;
        if ( (Flags & 0x1Fu) > 9 )
        {
          if ( (Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v18);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v18);
        }
        ++v9;
        p_mat4 = (Scaleform::Render::Matrix4x4<double> *)((char *)p_mat4 + 8);
      }
      while ( v9 < 16 );
      v13 = &v17->mat4;
      Scaleform::Render::Matrix4x4<double>::Transpose(&v17->mat4);
      v14 = v17;
      if ( v17->pDispObj )
      {
        Scaleform::Render::Matrix4x4<double>::operator Scaleform::Render::Matrix3x4<float>(v13, &result);
        memcpy((unsigned __int8 *)&dst, (unsigned __int8 *)&result, sizeof(dst));
        v14->pDispObj->SetMatrix3D(v14->pDispObj, &dst);
      }
    }
  }
}
