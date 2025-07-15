void __thiscall survarium::animation_space_graph_cook::translate_request_path(
        survarium::animation_space_graph_cook *this,
        const char *request,
        vostok::fs_new::virtual_path_string *new_request)
{
  vostok::fs_new::path_string_impl::assignf(
    new_request,
    "resources/npc/human/animation_space_graph/%s.space_graph",
    request);
}
