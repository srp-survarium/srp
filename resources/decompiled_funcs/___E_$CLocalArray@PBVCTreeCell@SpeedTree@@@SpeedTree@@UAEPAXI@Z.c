void *__thiscall SpeedTree::CLocalArray<SpeedTree::CTreeCell const *>::`vector deleting destructor'(
        void *this,
        char a2)
{
  SpeedTree::CLocalArray<SpeedTree::CTreeCell const *>::~CLocalArray<SpeedTree::CTreeCell const *>((int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
