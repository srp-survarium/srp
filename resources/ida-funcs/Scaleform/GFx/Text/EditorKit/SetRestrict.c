char __thiscall Scaleform::GFx::Text::EditorKit::SetRestrict(
        Scaleform::GFx::Text::EditorKit *this,
        const Scaleform::String *restrStr)
{
  char v3; // bl

  v3 = Scaleform::GFx::Text::EditorKit::ParseRestrict(
         this,
         (const char *)((restrStr->HeapTypeBits & 0xFFFFFFFC) + 8),
         (const char *)(*(_DWORD *)(restrStr->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF));
  Scaleform::String::operator=(&this->pRestrict.pObject->RestrictString, restrStr);
  return v3;
}
