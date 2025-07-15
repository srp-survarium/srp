void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteLineGradientStyle(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::InteractiveObject *Target; // eax
  Scaleform::GFx::InteractiveObject_vtbl **v3; // esi
  Scaleform::GFx::DrawingContext *v4; // edi
  Scaleform::GFx::Resource *LineComplexFill; // eax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(fn->ThisPtr) == Object_Sprite )
      Target = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].__vftable;
    else
      Target = 0;
  }
  else
  {
    Target = fn->Env->Target;
  }
  if ( Target )
  {
    v3 = &Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + Target->AvmObjOffset;
    v4 = (Scaleform::GFx::DrawingContext *)(*((int (__thiscall **)(Scaleform::GFx::InteractiveObject_vtbl *))v3[4]->~Scaleform::GFx::DisplayObjectBase
                                            + 81))(v3[4]);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v3[4]);
    Scaleform::GFx::DisplayObjectBase::InvalidateHitResult((Scaleform::GFx::DisplayObjectBase *)v3[4]);
    Scaleform::GFx::DrawingContext::AcquirePath(v4, 1);
    LineComplexFill = Scaleform::GFx::DrawingContext::CreateLineComplexFill(v4);
    if ( LineComplexFill )
      Scaleform::GFx::AS2::AvmSprite::SpriteCreateGradient(fn, (Scaleform::Render::ComplexFill *)LineComplexFill);
  }
}
