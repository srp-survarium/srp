void __thiscall Scaleform::GFx::AS3::Classes::fl_geom::Vector3D::Vector3D(
        Scaleform::GFx::AS3::Classes::fl_geom::Vector3D *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // ebx
  Scaleform::GFx::AS3::Instances::fl::Catch *v4; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v5; // esi
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::Catch *v8; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v9; // esi
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v10; // ecx
  unsigned int v11; // eax
  Scaleform::GFx::AS3::Instances::fl::Catch *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v13; // esi
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v14; // ecx
  unsigned int v15; // eax

  Scaleform::GFx::AS3::Class::Class(this, t);
  this->__vftable = (Scaleform::GFx::AS3::Classes::fl_geom::Vector3D_vtbl *)&Scaleform::GFx::AS3::Classes::fl_geom::Vector3D::`vftable';
  this->X_AXIS.pObject = 0;
  this->Y_AXIS.pObject = 0;
  this->Z_AXIS.pObject = 0;
  v3 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject[1].__vftable;
  v4 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(v3);
  v5 = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, v3);
    v5->x = 0.0;
    v5->__vftable = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D_vtbl *)&Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::`vftable';
    v5->y = 0.0;
    v5->z = 0.0;
    v5->w = 0.0;
  }
  else
  {
    v5 = 0;
  }
  pObject = this->X_AXIS.pObject;
  if ( v5 != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->X_AXIS.pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    this->X_AXIS.pObject = v5;
  }
  v8 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(v3);
  v9 = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)v8;
  if ( v8 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v8, v3);
    v9->x = 0.0;
    v9->__vftable = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D_vtbl *)&Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::`vftable';
    v9->y = 0.0;
    v9->z = 0.0;
    v9->w = 0.0;
  }
  else
  {
    v9 = 0;
  }
  v10 = this->Y_AXIS.pObject;
  if ( v9 != v10 )
  {
    if ( v10 )
    {
      if ( ((unsigned __int8)v10 & 1) != 0 )
      {
        this->Y_AXIS.pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)((char *)v10 - 1);
      }
      else
      {
        v11 = v10->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v11) != 0 )
        {
          v10->RefCount = v11 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
        }
      }
    }
    this->Y_AXIS.pObject = v9;
  }
  v12 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(v3);
  v13 = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)v12;
  if ( v12 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v12, v3);
    v13->x = 0.0;
    v13->__vftable = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D_vtbl *)&Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::`vftable';
    v13->y = 0.0;
    v13->z = 0.0;
    v13->w = 0.0;
  }
  else
  {
    v13 = 0;
  }
  v14 = this->Z_AXIS.pObject;
  if ( v13 != v14 )
  {
    if ( v14 )
    {
      if ( ((unsigned __int8)v14 & 1) != 0 )
      {
        this->Z_AXIS.pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)((char *)v14 - 1);
      }
      else
      {
        v15 = v14->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v15) != 0 )
        {
          v14->RefCount = v15 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
        }
      }
    }
    this->Z_AXIS.pObject = v13;
  }
  this->X_AXIS.pObject->x = 1.0;
  this->Y_AXIS.pObject->y = 1.0;
  this->Z_AXIS.pObject->z = 1.0;
}
