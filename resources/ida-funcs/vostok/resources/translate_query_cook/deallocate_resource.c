void __thiscall vostok::resources::translate_query_cook::deallocate_resource(
        vostok::resources::translate_query_cook *this,
        void *__formal)
{
  vostok::resources::translate_query_cook *v2; // [esp-2h] [ebp-4h] BYREF

  v2 = this;
  if ( !`vostok::resources::translate_query_cook::deallocate_resource'::`5'::debug_macro_helper_ignore_always )
  {
    HIBYTE(v2) = 0;
    vostok::debug::on_error(
      (bool *)&v2 + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/resources_cook_classes.h",
      "vostok::resources::translate_query_cook::deallocate_resource",
      (const char *)0x97,
      "unexpected",
      (const char *)v2);
    if ( vostok::debug::is_debugger_present() || HIBYTE(v2) )
      __debugbreak();
  }
}
