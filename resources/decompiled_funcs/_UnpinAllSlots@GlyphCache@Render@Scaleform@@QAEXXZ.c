void __thiscall Scaleform::Render::GlyphCache::UnpinAllSlots(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::TextMeshProvider *i; // eax
  unsigned int *v2; // edx
  Scaleform::Render::TextMeshProvider *j; // eax
  $4F3C021D145BED5403D04465E6CC3A78 *v4; // esi
  unsigned int *p_Capacity; // eax

  for ( i = this->TextInUse.Root.pNext; ; i = i->pNext )
  {
    v2 = this == (Scaleform::Render::GlyphCache *)-2924 ? 0 : &this->RectsToUpdate.Capacity;
    if ( i == (Scaleform::Render::TextMeshProvider *)v2 )
      break;
    i->Flags &= 0xFFFFFFF9;
  }
  for ( j = this->TextInPin.Root.pNext; ; j = j->pNext )
  {
    v4 = this == (Scaleform::Render::GlyphCache *)-2932 ? 0 : &this->TextInUse.Root.4;
    if ( j == (Scaleform::Render::TextMeshProvider *)v4 )
      break;
    j->Flags &= 0xFFFFFFF9;
  }
  if ( this == (Scaleform::Render::GlyphCache *)-2924 )
    p_Capacity = 0;
  else
    p_Capacity = &this->RectsToUpdate.Capacity;
  this->TextInUse.Root.pPrev = (Scaleform::Render::TextMeshProvider *)p_Capacity;
  this->TextInUse.Root.pNext = (Scaleform::Render::TextMeshProvider *)p_Capacity;
  if ( this == (Scaleform::Render::GlyphCache *)-2932 )
  {
    MEMORY[0] = 0;
    MEMORY[4] = 0;
    Scaleform::Render::GlyphQueue::UnpinAllSlots((Scaleform::Render::GlyphQueue *)0xFFFFFF04);
  }
  else
  {
    this->TextInPin.Root.pPrev = (Scaleform::Render::TextMeshProvider *)&this->TextInUse.Root.4;
    this->TextInPin.Root.pNext = (Scaleform::Render::TextMeshProvider *)&this->TextInUse.Root.4;
    Scaleform::Render::GlyphQueue::UnpinAllSlots(&this->Queue);
  }
}
