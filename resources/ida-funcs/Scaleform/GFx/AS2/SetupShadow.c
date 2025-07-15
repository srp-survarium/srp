void __usercall Scaleform::GFx::AS2::SetupShadow(
        Scaleform::GFx::XML::ElementNode *preal@<esi>,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASUserData *asobj)
{
  Scaleform::GFx::AS3::Object::UserDataHolder *v3; // eax
  bool v4; // zf

  if ( !preal->pShadow )
  {
    v3 = (Scaleform::GFx::AS3::Object::UserDataHolder *)preal->MemoryManager.pObject->pHeap->Alloc(
                                                          preal->MemoryManager.pObject->pHeap,
                                                          12u,
                                                          0);
    if ( v3 )
    {
      v3->pMovieView = (Scaleform::GFx::Movie *)&Scaleform::GFx::AS2::XMLShadowRef::`vftable';
      v3->pUserData = 0;
      v3[1].pMovieView = 0;
    }
    else
    {
      v3 = 0;
    }
    v4 = preal->Type == 1;
    preal->pShadow = (Scaleform::GFx::XML::ShadowRefBase *)v3;
    if ( v4 )
      Scaleform::GFx::AS2::SetupAttributes(penv, preal);
  }
  preal->pShadow[1].__vftable = (Scaleform::GFx::XML::ShadowRefBase_vtbl *)asobj;
  *(_DWORD *)&asobj[2].IsLastDispObj = preal;
}
