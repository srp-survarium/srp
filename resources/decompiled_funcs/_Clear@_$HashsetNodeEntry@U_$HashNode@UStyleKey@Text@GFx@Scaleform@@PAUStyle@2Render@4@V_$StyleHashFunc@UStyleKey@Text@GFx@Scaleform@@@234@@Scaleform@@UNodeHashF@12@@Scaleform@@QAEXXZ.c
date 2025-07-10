void __thiscall Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeHashF>::Clear(
        Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF> *this)
{
  volatile LONG *v2; // esi

  v2 = (volatile LONG *)(this->Value.First.Value.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  this->NextInChain = -2;
}
