void __cdecl Scaleform::ConstructorMov<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>>::DestructArray(
        Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *p,
        unsigned int count)
{
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *v2; // esi
  unsigned int v3; // edi
  Scaleform::WeakPtrProxy *pObject; // eax

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->pProxy.pObject;
      if ( v2->pProxy.pObject )
      {
        if ( pObject->RefCount-- == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
