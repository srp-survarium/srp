void __thiscall Scaleform::GFx::Button::~Button(Scaleform::GFx::Button *this)
{
  int *p_LastMouseFlags; // edi
  int v3; // eax
  int v4; // ecx
  Scaleform::RefCountNTSImpl **v5; // esi
  int v6; // ebx
  Scaleform::Render::ContextImpl::Entry *v7; // ecx
  int i; // [esp+10h] [ebp-4h]

  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::Button_vtbl *)&Scaleform::GFx::Button::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::Button::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  p_LastMouseFlags = &this->LastMouseFlags;
  for ( i = 3; i >= 0; --i )
  {
    v3 = *(p_LastMouseFlags - 2);
    v4 = *(p_LastMouseFlags - 3);
    p_LastMouseFlags -= 4;
    v5 = (Scaleform::RefCountNTSImpl **)(v4 + 8 * v3 - 8);
    if ( v3 )
    {
      v6 = v3;
      do
      {
        if ( *v5 )
          Scaleform::RefCountNTSImpl::Release(*v5);
        v5 -= 2;
        --v6;
      }
      while ( v6 );
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)p_LastMouseFlags[1]);
    v7 = (Scaleform::Render::ContextImpl::Entry *)*p_LastMouseFlags;
    if ( *p_LastMouseFlags )
    {
      if ( v7->RefCount-- == 1 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v7);
    }
  }
  Scaleform::GFx::InteractiveObject::~InteractiveObject(this);
}
