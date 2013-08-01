# BBActionSheet

Life is easier with blocks but UIActionSheet was built in a time before blocks. Enter BBActionSheet.

With BBActionSheet it’s far easier to keep code nice and simple, especially when you need to pass around an object. For example:

    - (void)tableView:(UITableView *)tableView accessoryButtonTappedForRowWithIndexPath:(NSIndexPath *)indexPath {
        BBToDo *toDo = [[self toDos] objectAtIndex:[indexPath row]];
        
        BBActionSheet *actionSheet = [[BBActionSheet alloc] initWithTitle:NSLocalizedString(@"Options", nil)];
        
        [actionSheet addButtonWithTitle:NSLocalizedString(@"Move to list…", nil) clicked:^{
            [self chooseListForToDo:toDo];
        }];
        
        [actionSheet addDestructiveButtonWithTitle:NSLocalizedString(@"Delete", nil) clicked:^{
            [self deleteToDo:toDo];
        }];
        
        [actionSheet addCancelButtonWithTitle:NSLocalizedString(@"Cancel", nil)];
        [actionSheet showInView:[self view]];
    }

## Installation

1. [Download the files](https://github.com/benrblakely/BBActionSheet/archive/master.zip).
2. Copy `BBActionSheet.h` and `BBActionSheet.m` into your project’s directory.
3. Drag the files into Xcode.
4. Add `#import "BBActionSheet.h"` to your project’s prefix header, e.g. `MyApp-Prefix.pch`.
5. Enjoy!
