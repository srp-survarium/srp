void __thiscall Scaleform::GFx::AS2::Object::Object(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASRefCountCollector *pcc)
{
  Scaleform::GFx::AS2::Object *pObject; // ecx
  unsigned int RefCount; // eax

  this->pRCC = pcc;
  this->RefCount = 1;
  this->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable';
  this->pUserDataHolder = 0;
  this->pProto.pObject = 0;
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)&Scaleform::GFx::AS2::Object::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AmpMarker::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Members.mHash.pTable = 0;
  this->ResolveHandler.Flags = 0;
  this->ResolveHandler.Function = 0;
  this->ResolveHandler.pLocalFrame = 0;
  this->pWatchpoints = 0;
  this->ArePropertiesSet = 0;
  this->IsListenerSet = 0;
  pObject = this->pProto.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->pProto.pObject = 0;
}


void __thiscall Scaleform::GFx::AS2::Object::Object(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // eax
  Scaleform::GFx::AS2::RefCountCollector<323> *pLoadQueueHead; // eax
  Scaleform::GFx::AS2::Object *pObject; // ecx
  unsigned int RefCount; // eax

  if ( psc->pContext && (pMovieRoot = psc->pContext->pMovieRoot) != 0 )
    pLoadQueueHead = (Scaleform::GFx::AS2::RefCountCollector<323> *)pMovieRoot->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    pLoadQueueHead = 0;
  this->pRCC = pLoadQueueHead;
  this->RefCount = 1;
  this->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable';
  this->pUserDataHolder = 0;
  this->pProto.pObject = 0;
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)&Scaleform::GFx::AS2::Object::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AmpMarker::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Members.mHash.pTable = 0;
  this->ResolveHandler.Flags = 0;
  this->ResolveHandler.Function = 0;
  this->ResolveHandler.pLocalFrame = 0;
  this->pWatchpoints = 0;
  this->ArePropertiesSet = 0;
  this->IsListenerSet = 0;
  pObject = this->pProto.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->pProto.pObject = 0;
}


void __thiscall Scaleform::GFx::AS2::Object::Object(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *proto)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323> *pLoadQueueHead; // ecx

  if ( psc->pContext && (pMovieRoot = psc->pContext->pMovieRoot) != 0 )
    pLoadQueueHead = (Scaleform::GFx::AS2::RefCountCollector<323> *)pMovieRoot->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    pLoadQueueHead = 0;
  this->pRCC = pLoadQueueHead;
  this->RefCount = 1;
  this->pUserDataHolder = 0;
  this->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable';
  this->pProto.pObject = 0;
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)&Scaleform::GFx::AS2::Object::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AmpMarker::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Members.mHash.pTable = 0;
  this->ResolveHandler.Flags = 0;
  this->ResolveHandler.Function = 0;
  this->ResolveHandler.pLocalFrame = 0;
  this->pWatchpoints = 0;
  this->ArePropertiesSet = 0;
  this->IsListenerSet = 0;
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    proto);
}


void __thiscall Scaleform::GFx::AS2::Object::Object(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::InteractiveObject *Target; // eax
  Scaleform::GFx::AS2::RefCountCollector<323> *v4; // eax
  Scaleform::GFx::AS2::Object *Prototype; // eax

  Target = penv->Target;
  if ( Target )
    v4 = *(Scaleform::GFx::AS2::RefCountCollector<323> **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)((*(int (__thiscall **)(int))(*((_DWORD *)&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable + Target->AvmObjOffset) + 4))(
                                                                                                 (int)Target
                                                                                               + 4
                                                                                               * Target->AvmObjOffset)
                                                                                             + 16)
                                                                                 + 16)
                                                                     + 28)
                                                         + 16);
  else
    v4 = 0;
  this->pRCC = v4;
  this->RefCount = 1;
  this->pUserDataHolder = 0;
  this->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable';
  this->pProto.pObject = 0;
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)&Scaleform::GFx::AS2::Object::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AmpMarker::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Members.mHash.pTable = 0;
  this->ResolveHandler.Flags = 0;
  this->ResolveHandler.Function = 0;
  this->ResolveHandler.pLocalFrame = 0;
  this->pWatchpoints = 0;
  this->ArePropertiesSet = 0;
  this->IsListenerSet = 0;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Object);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
}
