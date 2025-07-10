void __cdecl Scaleform::Render::StateBag::copyArrayAddRef(
        Scaleform::Render::State *d,
        Scaleform::Render::State *s,
        unsigned int count)
{
  unsigned int i; // ebx
  unsigned int ArraySize; // ecx

  for ( i = count; i; ++d )
  {
    ArraySize = s->ArraySize;
    d->DataValue = s->DataValue;
    d->ArraySize = ArraySize;
    (*(void (__thiscall **)(unsigned int, unsigned int, int))(*(_DWORD *)ArraySize + 4))(ArraySize, s->DataValue, 1);
    --i;
    ++s;
  }
}
