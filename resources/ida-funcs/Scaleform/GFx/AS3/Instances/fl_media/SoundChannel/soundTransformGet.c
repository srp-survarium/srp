void __thiscall Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::soundTransformGet(
        Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::Value::V1U v5; // eax
  Scaleform::GFx::AS3::Value::V1U v6; // ebx
  Scaleform::GFx::AS3::SoundObject *v7; // ecx
  int UsedSpace; // eax
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *v9; // ecx
  int v10; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform> trans; // [esp+10h] [ebp-24h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+24h] [ebp-10h] BYREF

  pObject = this->pTraits.pObject;
  v.Flags = 0;
  v.Bonus.pWeakProxy = 0;
  pVM = pObject->pVM;
  Scaleform::GFx::AS3::VM::Construct(pVM, "flash.media.SoundTransform", pVM->CurrentDomain, &v, 0, 0, 1);
  if ( pVM->HandleException
    || (v.Flags & 0x1F) == 0
    || (v5 = v.value.VS._1, (v.Flags & 0x1F) - 12 <= 3) && !v.value.VS._1.VInt )
  {
    if ( (v.Flags & 0x1F) <= 9 )
      return;
    if ( (v.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      return;
    }
LABEL_22:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    return;
  }
  v6 = v.value.VS._1;
  trans.pObject = (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)v.value.VS._1.VInt;
  if ( v.value.VS._1.VInt )
  {
    ++*(_DWORD *)(v.value.VS._1.VInt + 16);
    *(_DWORD *)(v5.VInt + 16) &= 0x8FBFFFFF;
  }
  v7 = this->pSoundObject.pObject;
  if ( v7 )
  {
    r.Flags = 0;
    r.Bonus.pWeakProxy = 0;
    UsedSpace = Scaleform::SysAllocPagedMalloc::GetUsedSpace(v7);
    v9 = (Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *)this->pSoundObject.pObject;
    *(double *)(v6.VInt + 32) = (double)(UsedSpace / 100);
    *(double *)(v6.VInt + 40) = (double)((int)Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyleCount(v9)
                                       / 100);
    if ( (r.Flags & 0x1F) > 9 )
    {
      if ( (r.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
    }
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    result,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&trans);
  if ( v6.VInt && !v6.VBool )
  {
    v10 = *(_DWORD *)(v6.VInt + 16);
    if ( (v10 & 0x3FFFFF) != 0 )
    {
      *(_DWORD *)(v6.VInt + 16) = v10 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6.VObj);
    }
  }
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      return;
    }
    goto LABEL_22;
  }
}
