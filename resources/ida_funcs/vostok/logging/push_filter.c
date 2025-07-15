void __cdecl vostok::logging::push_filter(
        vostok::logging::filter_tree *tree,
        vostok::fixed_string<16> *initiator,
        vostok::logging::verbosity verbosity,
        unsigned int thread_id)
{
  vostok::logging::filter_tree::push_filter(tree, initiator, verbosity, thread_id);
}
