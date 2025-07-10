BOOL __thiscall Scaleform::Render::SKI_Filter::UpdateBundleEntry(
        Scaleform::Render::SKI_Filter *this,
        Scaleform::GFx::Resource *d,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::TreeCacheRoot *tr,
        Scaleform::Render::Renderer2DImpl *r,
        int ibundles)
{
  Scaleform::Render::BundleEntry *v7; // eax
  int v8; // edx
  Scaleform::Render::SortKeyType Type; // ecx
  Scaleform::Render::SortKeyType v10; // ecx
  Scaleform::Render::FilterBundle *v11; // eax
  Scaleform::Render::Bundle *v12; // eax
  Scaleform::Render::Bundle *v13; // esi
  bool maskPresent; // [esp+10h] [ebp+8h]

  if ( !p->pBundle.pObject )
  {
    v7 = *(Scaleform::Render::BundleEntry **)ibundles;
    v8 = 0;
    maskPresent = 0;
    if ( *(_DWORD *)ibundles )
    {
      while ( 1 )
      {
        if ( v8 == 1 )
        {
          Type = v7->Key.pImpl->Type;
          if ( Type == SortKey_MaskStart || Type == SortKey_MaskStartClipped || Type == SortKey_MaskEnd )
            break;
        }
        v10 = v7->Key.pImpl->Type;
        if ( v10 == SortKey_FilterEnd )
        {
          if ( --v8 <= 0 )
            goto LABEL_16;
        }
        else if ( v10 == SortKey_FilterStart )
        {
          ++v8;
        }
        if ( v7 != *(Scaleform::Render::BundleEntry **)(ibundles + 4) )
        {
          v7 = v7->pNextPattern;
          if ( v7 )
            continue;
        }
        goto LABEL_16;
      }
      maskPresent = 1;
    }
LABEL_16:
    ibundles = 67;
    v11 = (Scaleform::Render::FilterBundle *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                               Scaleform::Memory::pGlobalHeap,
                                               tr,
                                               72,
                                               &ibundles);
    if ( v11 )
    {
      Scaleform::Render::FilterBundle::FilterBundle(v11, r->pHal.pObject, d, maskPresent);
      v13 = v12;
    }
    else
    {
      v13 = 0;
    }
    Scaleform::Render::BundleEntry::SetBundle(p, v13, 0);
    if ( v13 )
      Scaleform::RefCountNTSImpl::Release(v13);
  }
  return p->pBundle.pObject != 0;
}
