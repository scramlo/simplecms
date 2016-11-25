# simplecms
A zero-configuration, flat file CMS using PHP and JSON.


##Admin Themes
Add a new JSON object in the following format. The styles are output in a `style` tag in the `head`.

```
{
            "title": "Dark Knight",
            "active": true,
            "css": [
                {
                    "body": [
                        {
                            "background-color": "#3b3b3b",
                            "color": "white"
                        }
                    ],
                    "#side-panel": [
                        {
                            "background-color": "slateGray"
                        }
                    ],
                    "hr": [
                        {
                            "background-color": "white"
                        }
                    ]
                }
            ]
        }
```
