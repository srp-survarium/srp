bool __cdecl SpeedTree::CCore::UnlockTmpHeapBlock(int a1)
{
  return SpeedTree::CSharedHeapBlock::Unlock((SpeedTree::CSharedHeapBlock *)((char *)&unk_A9B140 + 276 * a1));
}
