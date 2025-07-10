BOOL __cdecl vostok::render::constant_data_predicate(
        const vostok::render::data_indexer *left,
        const vostok::render::data_indexer *right)
{
  return left->class_id < right->class_id;
}
