BOOL __cdecl vostok::ai::planning::is_block_on_block(
        const vostok::ai::planning::block *const first_block,
        const vostok::ai::planning::block *const second_block)
{
  return second_block->block_above == first_block;
}
