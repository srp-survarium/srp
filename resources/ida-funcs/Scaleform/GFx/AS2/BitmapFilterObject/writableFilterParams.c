Scaleform::Render::BlurFilterParams *__thiscall Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(
        Scaleform::GFx::AS2::BitmapFilterObject *this)
{
  Scaleform::Render::Filter *pObject; // edi
  Scaleform::MemoryHeap *v3; // eax
  int v4; // eax
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::Render::Filter *v6; // edi
  Scaleform::Render::Filter *v7; // esi
  int Type; // eax
  bool v9; // cc
  Scaleform::Render::BlurFilterParams *result; // eax

  if ( (`Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::`local static guard' & 1) == 0 )
  {
    `Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::`local static guard' |= 1u;
    `Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams.BlurX = 100.0;
    `Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams.Mode = 0;
    `Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams.BlurY = 100.0;
    `Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams.Passes = 1;
    `Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams.Offset.x = 0.0;
    *(_WORD *)&`Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams.Colors[0].Channels.Green = 0;
    `Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams.Offset.y = 0.0;
    `Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams.Colors[0].Channels.Blue = 0;
    `Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams.Colors[0].Channels.Alpha = -1;
    `Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams.Strength = 1.0;
    *(_WORD *)&`Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams.Colors[1].Channels.Green = 0;
    `Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams.Colors[1].Channels.Blue = 0;
    `Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams.Colors[1].Channels.Alpha = 0;
  }
  pObject = this->pFilter.pObject;
  if ( pObject && pObject->Frozen )
  {
    v3 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    v4 = (int)pObject->Clone(pObject, v3);
    v5 = (Scaleform::RefCountVImpl *)this->pFilter.pObject;
    v6 = (Scaleform::Render::Filter *)v4;
    if ( v5 )
      Scaleform::RefCountImpl::Release(v5);
    this->pFilter.pObject = v6;
  }
  v7 = this->pFilter.pObject;
  if ( !v7 )
    return &`Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams;
  Type = v7->Type;
  if ( Type < 0 )
    return &`Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams;
  v9 = Type <= 5;
  result = (Scaleform::Render::BlurFilterParams *)&v7[1];
  if ( !v9 )
    return &`Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams'::`2'::unavailableParams;
  return result;
}
