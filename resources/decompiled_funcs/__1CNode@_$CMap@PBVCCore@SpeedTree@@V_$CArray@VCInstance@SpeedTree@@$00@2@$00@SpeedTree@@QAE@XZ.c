void __thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::CNode::~CNode(
        int this)
{
  SpeedTree::CArray<SpeedTree::CInstance,1> *v1; // [esp+4h] [ebp-40h]

  v1 = (SpeedTree::CArray<SpeedTree::CInstance,1> *)(this + 4);
  *(_DWORD *)(this + 4) = &SpeedTree::CArray<SpeedTree::CInstance,1>::`vftable';
  if ( *(_BYTE *)(this + 20) )
    SpeedTree::CArray<SpeedTree::CInstance,1>::SetExternalMemory(v1, 0, 0);
  SpeedTree::CArray<SpeedTree::CInstance,1>::clear(v1);
}
