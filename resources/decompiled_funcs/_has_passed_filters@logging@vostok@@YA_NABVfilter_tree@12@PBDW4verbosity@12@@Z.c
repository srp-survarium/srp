bool __cdecl vostok::logging::has_passed_filters(
        vostok::logging::filter_tree *tree,
        const char *initiator,
        vostok::logging::verbosity verbosity)
{
  return vostok::logging::filter_tree::has_passed_filters(tree, initiator, verbosity);
}
