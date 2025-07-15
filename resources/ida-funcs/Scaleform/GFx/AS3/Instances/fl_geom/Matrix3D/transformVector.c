void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::transformVector(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edi
  Scaleform::GFx::AS3::Instances::fl::Catch *v7; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v8; // esi
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v9; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::VM::Error v11; // [esp+8h] [ebp-38h] BYREF
  Scaleform::Render::Point3<double> pdIn; // [esp+10h] [ebp-30h] BYREF
  Scaleform::Render::Point3<double> pdOut; // [esp+28h] [ebp-18h] BYREF

  if ( v )
  {
    pdIn.x = v->x;
    pdIn.y = v->y;
    pdIn.z = v->z;
    Scaleform::Render::Matrix4x4<double>::Transform(&this->mat4, &pdOut, &pdIn);
    pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v->pTraits.pObject;
    v7 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(pObject);
    v8 = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)v7;
    if ( v7 )
    {
      Scaleform::GFx::AS3::Instances::fl::Object::Object(v7, pObject);
      v8->x = 0.0;
      v8->__vftable = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D_vtbl *)&Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::`vftable';
      v8->y = 0.0;
      v8->z = 0.0;
      v8->w = 0.0;
    }
    else
    {
      v8 = 0;
    }
    *(Scaleform::Render::Point3<double> *)&v8->x = pdOut;
    v9 = result->pObject;
    if ( v8 != result->pObject )
    {
      if ( v9 )
      {
        if ( ((unsigned __int8)v9 & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)((char *)v9 - 1);
          result->pObject = v8;
          return;
        }
        RefCount = v9->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v9->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
        }
      }
      result->pObject = v8;
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v4);
    pNode = v11.Message.pNode;
    --v11.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
