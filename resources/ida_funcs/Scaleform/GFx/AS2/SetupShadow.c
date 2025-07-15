void __usercall Scaleform::GFx::AS2::SetupShadow(
        Scaleform::GFx::XML::ElementNode *preal@<esi>,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::XML::ShadowRefBase_vtbl *asobj)
{
  Scaleform::GFx::XML::ShadowRefBase *v3; // eax
  bool v4; // zf

  if ( !preal->pShadow )
  {
    v3 = (Scaleform::GFx::XML::ShadowRefBase *)preal->MemoryManager.pObject->pHeap->Alloc(
                                                 preal->MemoryManager.pObject->pHeap,
                                                 12,
                                                 0);
    if ( v3 )
    {
      v3->__vftable = (Scaleform::GFx::XML::ShadowRefBase_vtbl *)&Scaleform::GFx::AS2::XMLShadowRef::`vftable';
      v3[1].__vftable = 0;
      v3[2].__vftable = 0;
    }
    else
    {
      v3 = 0;
    }
    v4 = preal->Type == 1;
    preal->pShadow = v3;
    if ( v4 )
      Scaleform::GFx::AS2::SetupAttributes(penv, preal);
  }
  preal->pShadow[1].__vftable = asobj;
  asobj[14].~Scaleform::GFx::XML::ShadowRefBase = (void (__thiscall *)(Scaleform::GFx::XML::ShadowRefBase *))preal;
}
