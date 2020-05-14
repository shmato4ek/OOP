#include "Text.h"
void Do(Text& t, void (Text::* func)())
{
    (t.*func)();
}
int main()
{
    Text text("AaBbCcDdEeVVVVV");
    Do(text, &Text::Search);
}