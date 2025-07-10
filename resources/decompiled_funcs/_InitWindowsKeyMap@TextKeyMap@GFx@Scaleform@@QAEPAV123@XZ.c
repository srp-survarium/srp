Scaleform::GFx::TextKeyMap *__thiscall Scaleform::GFx::TextKeyMap::InitWindowsKeyMap(Scaleform::GFx::TextKeyMap *this)
{
  Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy> *p_Map; // esi
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned int Size; // [esp-Ch] [ebp-2Ch]
  unsigned int v29; // [esp-Ch] [ebp-2Ch]
  unsigned int v30; // [esp-Ch] [ebp-2Ch]
  unsigned int v31; // [esp-Ch] [ebp-2Ch]
  unsigned int v32; // [esp-Ch] [ebp-2Ch]
  unsigned int v33; // [esp-Ch] [ebp-2Ch]
  unsigned int v34; // [esp-Ch] [ebp-2Ch]
  unsigned int v35; // [esp-Ch] [ebp-2Ch]
  unsigned int v36; // [esp-Ch] [ebp-2Ch]
  unsigned int v37; // [esp-Ch] [ebp-2Ch]
  unsigned int v38; // [esp-Ch] [ebp-2Ch]
  unsigned int v39; // [esp-Ch] [ebp-2Ch]
  unsigned int v40; // [esp-Ch] [ebp-2Ch]
  unsigned int v41; // [esp-Ch] [ebp-2Ch]
  unsigned int v42; // [esp-Ch] [ebp-2Ch]
  unsigned int v43; // [esp-Ch] [ebp-2Ch]
  unsigned int v44; // [esp-Ch] [ebp-2Ch]
  unsigned int v45; // [esp-Ch] [ebp-2Ch]
  unsigned int v46; // [esp-Ch] [ebp-2Ch]
  unsigned int v47; // [esp-Ch] [ebp-2Ch]
  unsigned int v48; // [esp-Ch] [ebp-2Ch]
  unsigned int v49; // [esp-Ch] [ebp-2Ch]
  unsigned int v50; // [esp-Ch] [ebp-2Ch]
  unsigned int v51; // [esp-Ch] [ebp-2Ch]
  Scaleform::GFx::TextKeyMap::KeyMapEntry val; // [esp+10h] [ebp-10h] BYREF

  p_Map = &this->Map;
  Size = this->Map.Data.Size;
  val.Action = KeyAct_EnterSelectionMode;
  val.KeyCode = 16;
  val.SpecKeysPressed = 0;
  val.mState = State_Down;
  v3 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
         &this->Map,
         0,
         Size,
         &val,
         Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v3,
    &val);
  v29 = p_Map->Data.Size;
  val.Action = KeyAct_LeaveSelectionMode;
  val.KeyCode = 16;
  val.SpecKeysPressed = 0;
  val.mState = State_Up;
  v4 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
         p_Map,
         0,
         v29,
         &val,
         Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v4,
    &val);
  v30 = p_Map->Data.Size;
  val.Action = KeyAct_Up;
  val.KeyCode = 38;
  val.SpecKeysPressed = 0;
  val.mState = State_Down;
  v5 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
         p_Map,
         0,
         v30,
         &val,
         Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v5,
    &val);
  v31 = p_Map->Data.Size;
  val.Action = KeyAct_Down;
  val.KeyCode = 40;
  val.SpecKeysPressed = 0;
  val.mState = State_Down;
  v6 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
         p_Map,
         0,
         v31,
         &val,
         Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v6,
    &val);
  val.Action = KeyAct_Left;
  v32 = p_Map->Data.Size;
  val.KeyCode = 37;
  val.SpecKeysPressed = 0;
  val.mState = State_Down;
  v7 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
         p_Map,
         0,
         v32,
         &val,
         Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v7,
    &val);
  v33 = p_Map->Data.Size;
  val.Action = KeyAct_Right;
  val.KeyCode = 39;
  val.SpecKeysPressed = 0;
  val.mState = State_Down;
  v8 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
         p_Map,
         0,
         v33,
         &val,
         Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v8,
    &val);
  v34 = p_Map->Data.Size;
  val.Action = KeyAct_PageUp;
  val.KeyCode = 33;
  val.SpecKeysPressed = 0;
  val.mState = State_Down;
  v9 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
         p_Map,
         0,
         v34,
         &val,
         Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v9,
    &val);
  v35 = p_Map->Data.Size;
  val.Action = KeyAct_PageDown;
  val.KeyCode = 34;
  val.SpecKeysPressed = 0;
  val.mState = State_Down;
  v10 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v35,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v10,
    &val);
  v36 = p_Map->Data.Size;
  val.Action = KeyAct_LineHome;
  val.KeyCode = 36;
  val.SpecKeysPressed = 0;
  val.mState = State_Down;
  v11 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v36,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v11,
    &val);
  v37 = p_Map->Data.Size;
  val.Action = KeyAct_LineEnd;
  val.KeyCode = 35;
  val.SpecKeysPressed = 0;
  val.mState = State_Down;
  v12 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v37,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v12,
    &val);
  v38 = p_Map->Data.Size;
  val.Action = KeyAct_PageHome;
  val.KeyCode = 33;
  val.SpecKeysPressed = 2;
  val.mState = State_Down;
  v13 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v38,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v13,
    &val);
  v39 = p_Map->Data.Size;
  val.Action = KeyAct_PageEnd;
  val.KeyCode = 34;
  val.SpecKeysPressed = 2;
  val.mState = State_Down;
  v14 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v39,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v14,
    &val);
  v40 = p_Map->Data.Size;
  val.Action = KeyAct_DocHome;
  val.KeyCode = 36;
  val.SpecKeysPressed = 2;
  val.mState = State_Down;
  v15 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v40,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v15,
    &val);
  val.Action = KeyAct_DocEnd;
  v41 = p_Map->Data.Size;
  val.KeyCode = 35;
  val.SpecKeysPressed = 2;
  val.mState = State_Down;
  v16 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v41,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v16,
    &val);
  v42 = p_Map->Data.Size;
  val.Action = KeyAct_Backspace;
  val.KeyCode = 8;
  val.SpecKeysPressed = 0;
  val.mState = State_Down;
  v17 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v42,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v17,
    &val);
  v43 = p_Map->Data.Size;
  val.Action = KeyAct_Delete;
  val.KeyCode = 46;
  val.SpecKeysPressed = 0;
  val.mState = State_Down;
  v18 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v43,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v18,
    &val);
  v44 = p_Map->Data.Size;
  val.Action = KeyAct_Return;
  val.KeyCode = 13;
  val.SpecKeysPressed = 0;
  val.mState = State_Down;
  v19 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v44,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v19,
    &val);
  v45 = p_Map->Data.Size;
  val.Action = KeyAct_Copy;
  val.KeyCode = 67;
  val.SpecKeysPressed = 2;
  val.mState = State_Down;
  v20 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v45,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v20,
    &val);
  v46 = p_Map->Data.Size;
  val.Action = KeyAct_Copy;
  val.KeyCode = 45;
  val.SpecKeysPressed = 2;
  val.mState = State_Down;
  v21 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v46,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v21,
    &val);
  v47 = p_Map->Data.Size;
  val.Action = KeyAct_Paste;
  val.KeyCode = 86;
  val.SpecKeysPressed = 2;
  val.mState = State_Down;
  v22 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v47,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v22,
    &val);
  v48 = p_Map->Data.Size;
  val.Action = KeyAct_Paste;
  val.KeyCode = 45;
  val.SpecKeysPressed = 1;
  val.mState = State_Down;
  v23 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v48,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v23,
    &val);
  v49 = p_Map->Data.Size;
  val.Action = KeyAct_Cut;
  val.KeyCode = 88;
  val.SpecKeysPressed = 2;
  val.mState = State_Down;
  v24 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v49,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v24,
    &val);
  val.Action = KeyAct_Cut;
  v50 = p_Map->Data.Size;
  val.KeyCode = 46;
  val.SpecKeysPressed = 1;
  val.mState = State_Down;
  v25 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v50,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v25,
    &val);
  v51 = p_Map->Data.Size;
  val.Action = KeyAct_SelectAll;
  val.KeyCode = 65;
  val.SpecKeysPressed = 2;
  val.mState = State_Down;
  v26 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TextKeyMap::KeyMapEntry,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,Scaleform::GFx::TextKeyMap::KeyMapEntry const &)>(
          p_Map,
          0,
          v51,
          &val,
          Scaleform::GFx::`anonymous namespace'::KeyMapEntryComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_Map,
    v26,
    &val);
  return this;
}
