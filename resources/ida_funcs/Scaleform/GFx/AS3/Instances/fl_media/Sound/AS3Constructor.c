void __thiscall Scaleform::GFx::AS3::Instances::fl_media::Sound::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_media::Sound *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::ASVM *pVM; // edi
  int v5; // eax
  Scaleform::GFx::AS3::SoundObject *v6; // eax
  Scaleform::GFx::AS3::SoundObject *v7; // eax
  Scaleform::GFx::AS3::SoundObject *v8; // ebx
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl_media::SoundLoaderContext *VInt; // ebp
  Scaleform::GFx::AS3::Value r; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *req; // [esp+24h] [ebp+8h]

  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  v5 = (int)pVM->pMovieRoot->pMovieImpl->GetHeap(pVM->pMovieRoot->pMovieImpl);
  v6 = (Scaleform::GFx::AS3::SoundObject *)(*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v5 + 40))(v5, 40, 0);
  if ( v6 )
  {
    Scaleform::GFx::AS3::SoundObject::SoundObject(v6, pVM, this);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pSoundObject.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pSoundObject.pObject = v8;
  if ( this->pSoundResource.pObject )
    Scaleform::GFx::AS3::SoundObject::AttachResource(v8, this->pSoundResource.pObject);
  if ( argc && Scaleform::GFx::AS3::VM::IsOfType(pVM, argv, "flash.net.URLRequest", pVM->CurrentDomain) )
  {
    VInt = 0;
    req = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)argv->value.VS._1.VInt;
    if ( argc >= 2
      && Scaleform::GFx::AS3::VM::IsOfType(pVM, argv + 1, "flash.media.SoundLoaderContext", pVM->CurrentDomain) )
    {
      VInt = (Scaleform::GFx::AS3::Instances::fl_media::SoundLoaderContext *)argv->value.VS._1.VInt;
    }
    r.Flags = 0;
    r.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Instances::fl_media::Sound::load(this, &r, req, VInt);
    if ( (r.Flags & 0x1F) > 9 )
    {
      if ( (r.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
    }
  }
}
