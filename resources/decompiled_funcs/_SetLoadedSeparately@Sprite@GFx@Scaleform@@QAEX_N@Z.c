void __userpurge Scaleform::GFx::Sprite::SetLoadedSeparately(
        Scaleform::GFx::Sprite *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        bool v)
{
  unsigned __int8 Flags; // al
  unsigned __int8 v5; // al

  Flags = this->Flags;
  if ( v )
    v5 = Flags | 0x10;
  else
    v5 = Flags & 0xEF;
  this->Flags = v5;
  if ( v )
    Scaleform::GFx::DisplayObjContainer::AssignRootNode(this, a2, a3, 0);
}
