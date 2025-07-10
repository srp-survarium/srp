SpeedTree::CMap<SpeedTree::CCore const *,int,1> *__thiscall SpeedTree::CMap<SpeedTree::CCore const *,int,1>::`scalar deleting destructor'(
        SpeedTree::CMap<SpeedTree::CCore const *,int,1> *this,
        char a2)
{
  SpeedTree::CMap<SpeedTree::CCore const *,int,1>::~CMap<SpeedTree::CCore const *,int,1>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
