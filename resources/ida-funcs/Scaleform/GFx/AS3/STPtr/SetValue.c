Scaleform::GFx::AS3::STPtr *__thiscall Scaleform::GFx::AS3::STPtr::SetValue(
        Scaleform::GFx::AS3::STPtr *this,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int v3; // eax
  int v4; // esi
  Scaleform::GFx::AS3::Value::ObjectTag ObjectTag; // eax
  int v6; // edx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v8; // ecx
  int v9; // eax
  Scaleform::GFx::AS3::STPtr *result; // eax

  v3 = v->Flags & 0x1F;
  v4 = 0;
  if ( (v3 - 12 <= 3 || v3 == 11) && v->value.VS._1.VInt )
  {
    ObjectTag = Scaleform::GFx::AS3::Value::GetObjectTag(v);
    v4 = v6 | ObjectTag;
  }
  pObject = this->pObject;
  if ( (Scaleform::GFx::AS3::GASRefCountBase *)v4 == this->pObject )
    return this;
  if ( pObject )
  {
    v8 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((unsigned int)pObject & 0xFFFFFFF9);
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pObject = (Scaleform::GFx::AS3::GASRefCountBase *)((char *)pObject - 1);
    }
    else
    {
      v9 = *(_DWORD *)(((unsigned int)pObject & 0xFFFFFFF9) + 0x10);
      if ( (v9 & 0x3FFFFF) != 0 )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
      }
    }
  }
  this->pObject = (Scaleform::GFx::AS3::GASRefCountBase *)v4;
  result = this;
  if ( v4 )
    *(_DWORD *)((v4 & 0xFFFFFFF8) + 16) = (*(_DWORD *)((v4 & 0xFFFFFFF8) + 16) + 1) & 0x8FBFFFFF;
  return result;
}
