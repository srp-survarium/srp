void __thiscall Scaleform::GFx::AMP::FontVisitor::Visit(
        Scaleform::GFx::AMP::FontVisitor *this,
        Scaleform::GFx::MovieDef *__formal,
        Scaleform::GFx::Resource *presource,
        Scaleform::GFx::ResourceId rid,
        const char *a5)
{
  const __m128i *v6; // eax
  Scaleform::GFx::Resource_vtbl *v7; // eax
  int v8; // eax
  unsigned int Size; // edx
  void *v10; // esi
  Scaleform::String src; // [esp+8h] [ebp-68h] BYREF
  __m128i pbuffer[6]; // [esp+Ch] [ebp-64h] BYREF

  Scaleform::String::String(&src);
  v6 = (const __m128i *)(*((int (__thiscall **)(Scaleform::GFx::Resource_vtbl *))presource[1].~Scaleform::GFx::Resource
                         + 1))(presource[1].__vftable);
  Scaleform::String::operator=(&src, v6);
  v7 = presource[1].__vftable;
  if ( ((int)v7[1].GetKey & 2) != 0 )
  {
    Scaleform::String::AppendString(&src, (const __m128i *)" - Bold", 0xFFFFFFFF);
  }
  else if ( ((int)v7[1].GetKey & 1) != 0 )
  {
    Scaleform::String::AppendString(&src, (const __m128i *)" - Italic", 0xFFFFFFFF);
  }
  v8 = (*((int (__thiscall **)(Scaleform::GFx::Resource_vtbl *))presource[1].~Scaleform::GFx::Resource + 18))(presource[1].__vftable);
  Scaleform::SFsprintf(pbuffer[0].m128i_i8, 0x64u, ", %d glyphs", v8);
  Scaleform::String::AppendString(&src, pbuffer, 0xFFFFFFFF);
  if ( ((int)presource[1].__vftable[1].GetKey & 0x2000) == 0 )
    Scaleform::String::AppendString(&src, (const __m128i *)", static only", 0xFFFFFFFF);
  Scaleform::String::AppendString(&src, (const __m128i *)" (", 0xFFFFFFFF);
  Scaleform::GFx::ResourceId::GenerateIdString(&rid, pbuffer[0].m128i_i8, 9u, 0);
  Scaleform::String::AppendString(&src, pbuffer, 0xFFFFFFFF);
  Scaleform::String::AppendString(&src, (const __m128i *)")", 0xFFFFFFFF);
  Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Fonts.Data,
    &this->Fonts,
    this->Fonts.Data.Size + 1);
  Size = this->Fonts.Data.Size;
  if ( &this->Fonts.Data.Data[Size] != (Scaleform::String *)4 )
    Scaleform::String::String(&this->Fonts.Data.Data[Size - 1], &src);
  v10 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
}
