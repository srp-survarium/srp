void __thiscall Scaleform::GFx::AS3::Instances::fl_media::Sound::play(
        Scaleform::GFx::AS3::Instances::fl_media::Sound *this,
        Scaleform::GFx::AS3::Value *result,
        long double startTime,
        int loops,
        Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *sndTransform)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *VInt; // ebx
  Scaleform::GFx::Resource *v9; // ecx
  Scaleform::RefCountVImpl *v10; // ecx
  Scaleform::GFx::AS3::SoundObject *v11; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel> pchan; // [esp+10h] [ebp-24h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+24h] [ebp-10h] BYREF

  pObject = this->pTraits.pObject;
  v.Flags = 0;
  v.Bonus.pWeakProxy = 0;
  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  pVM = pObject->pVM;
  Scaleform::GFx::AS3::VM::Construct(pVM, "flash.media.SoundChannel", pVM->CurrentDomain, &v, 0, 0, 1);
  if ( pVM->HandleException
    || (v.Flags & 0x1F) == 0
    || (VInt = (Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *)v.value.VS._1.VInt, (v.Flags & 0x1F) - 12 <= 3)
    && !v.value.VS._1.VInt )
  {
    if ( (r.Flags & 0x1F) <= 9 )
      goto LABEL_26;
    if ( (r.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
      goto LABEL_26;
    }
LABEL_25:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
    goto LABEL_26;
  }
  pchan.pObject = (Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *)v.value.VS._1.VInt;
  if ( v.value.VS._1.VInt )
  {
    ++*(_DWORD *)(v.value.VS._1.VInt + 16);
    VInt->RefCount &= 0x8FBFFFFF;
  }
  v9 = (Scaleform::GFx::Resource *)this->pSoundObject.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::AddRef(v9);
  v10 = (Scaleform::RefCountVImpl *)VInt->pSoundObject.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  VInt->pSoundObject.pObject = this->pSoundObject.pObject;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->pChannel,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&pchan);
  v11 = this->pSoundObject.pObject;
  if ( v11 )
    Scaleform::GFx::AS3::SoundObject::Play(v11, (int)startTime, loops);
  if ( sndTransform )
    Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::soundTransformSet(VInt, &r, sndTransform);
  Scaleform::GFx::AS3::Value::Assign(result, VInt);
  if ( VInt )
  {
    if ( ((unsigned __int8)VInt & 1) == 0 )
    {
      RefCount = VInt->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        VInt->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VInt);
      }
    }
  }
  if ( (r.Flags & 0x1F) > 9 )
  {
    if ( (r.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
      goto LABEL_26;
    }
    goto LABEL_25;
  }
LABEL_26:
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
}
