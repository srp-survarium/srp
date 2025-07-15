BOOL __thiscall Scaleform::Render::SKI_Filter::UpdateBundleEntry(
        Scaleform::Render::SKI_Filter *this,
        Scaleform::GFx::Resource *d,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::TreeCacheRoot *tr,
        Scaleform::Render::Renderer2DImpl *r,
        int ibundles)
{
  _DWORD *v7; // eax
  int v8; // edx
  int v9; // ecx
  int v10; // ecx
  Scaleform::Render::FilterBundle *v11; // eax
  Scaleform::Render::Bundle *v12; // eax
  Scaleform::Render::Bundle *v13; // esi
  bool v15; // [esp+10h] [ebp+8h]

  if ( !p->pBundle.pObject )
  {
    v7 = *(_DWORD **)ibundles;
    v8 = 0;
    v15 = 0;
    if ( *(_DWORD *)ibundles )
    {
      while ( 1 )
      {
        if ( v8 == 1 )
        {
          v9 = *(_DWORD *)(v7[3] + 4);
          if ( v9 == 4 || v9 == 5 || v9 == 6 )
            break;
        }
        v10 = *(_DWORD *)(v7[3] + 4);
        if ( v10 == 10 )
        {
          if ( --v8 <= 0 )
            goto LABEL_16;
        }
        else if ( v10 == 9 )
        {
          ++v8;
        }
        if ( v7 != *(_DWORD **)(ibundles + 4) )
        {
          v7 = (_DWORD *)*v7;
          if ( v7 )
            continue;
        }
        goto LABEL_16;
      }
      v15 = 1;
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
      Scaleform::Render::FilterBundle::FilterBundle(v11, r->pHal.pObject, d, v15);
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
