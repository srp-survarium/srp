void __thiscall Scaleform::GFx::AS3::Classes::fl_geom::Vector3D::~Vector3D(
        Scaleform::GFx::AS3::Classes::fl_geom::Vector3D *this)
{
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v4; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v6; // ecx
  unsigned int v7; // eax

  pObject = this->Z_AXIS.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Z_AXIS.pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)((char *)pObject - 1);
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
  v4 = this->Y_AXIS.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->Y_AXIS.pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v5) != 0 )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
  v6 = this->X_AXIS.pObject;
  if ( v6 )
  {
    if ( ((unsigned __int8)v6 & 1) != 0 )
    {
      this->X_AXIS.pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)((char *)v6 - 1);
      Scaleform::GFx::AS3::Class::~Class(this);
      return;
    }
    v7 = v6->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & v7) != 0 )
    {
      v6->RefCount = v7 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
    }
  }
  Scaleform::GFx::AS3::Class::~Class(this);
}
