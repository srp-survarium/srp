void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::PushBack(
        Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4> *this,
        const Scaleform::Render::TmpTextMeshEntry *val)
{
  unsigned int v3; // esi

  v3 = this->Size >> 6;
  if ( v3 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(this, this->Size >> 6);
  qmemcpy(&this->Pages[v3][this->Size++ & 0x3F], val, sizeof(this->Pages[v3][this->Size++ & 0x3F]));
}
