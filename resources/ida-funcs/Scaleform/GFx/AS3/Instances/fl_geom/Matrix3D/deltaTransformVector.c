void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::deltaTransformVector(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edi
  long double v7; // st6
  long double v8; // st5
  Scaleform::GFx::AS3::Instances::fl::Object *v9; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v10; // esi
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v11; // ecx
  unsigned int RefCount; // eax
  long double pdOuta; // [esp+8h] [ebp-A0h]
  double pdOut; // [esp+8h] [ebp-A0h]
  long double pdOut_8a; // [esp+10h] [ebp-98h]
  double pdOut_8; // [esp+10h] [ebp-98h]
  long double pdOut_16a; // [esp+18h] [ebp-90h]
  double pdOut_16; // [esp+18h] [ebp-90h]
  Scaleform::GFx::AS3::VM::Error v19; // [esp+20h] [ebp-88h] BYREF
  Scaleform::Render::Matrix4x4<double> mat4NoTrans; // [esp+28h] [ebp-80h] BYREF

  if ( v )
  {
    pdOuta = v->x;
    pdOut_8a = v->y;
    pdOut_16a = v->z;
    memcpy((int)&mat4NoTrans, (const __m128i *)&this->mat4, sizeof(mat4NoTrans));
    pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v->pTraits.pObject;
    v7 = pdOut_8a;
    v8 = pdOuta;
    pdOut = mat4NoTrans.M[0][2] * pdOut_16a + mat4NoTrans.M[0][1] * pdOut_8a + mat4NoTrans.M[0][0] * pdOuta + 0.0;
    pdOut_8 = mat4NoTrans.M[1][1] * pdOut_8a + mat4NoTrans.M[1][0] * v8 + mat4NoTrans.M[1][2] * pdOut_16a + 0.0;
    pdOut_16 = pdOut_16a * mat4NoTrans.M[2][2] + v8 * mat4NoTrans.M[2][0] + v7 * mat4NoTrans.M[2][1] + 0.0;
    v9 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(pObject);
    v10 = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)v9;
    if ( v9 )
    {
      Scaleform::GFx::AS3::Instances::fl::Object::Object(v9, pObject);
      v10->x = 0.0;
      v10->__vftable = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D_vtbl *)&Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::`vftable';
      v10->y = 0.0;
      v10->z = 0.0;
      v10->w = 0.0;
    }
    else
    {
      v10 = 0;
    }
    v10->x = pdOut;
    v10->y = pdOut_8;
    v10->z = pdOut_16;
    v11 = result->pObject;
    if ( v10 != result->pObject )
    {
      if ( v11 )
      {
        if ( ((unsigned __int8)v11 & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)((char *)v11 - 1);
          result->pObject = v10;
          return;
        }
        RefCount = v11->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
        }
      }
      result->pObject = v10;
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v19, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v4);
    pNode = v19.Message.pNode;
    --v19.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
