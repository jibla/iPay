iPay
==========

iPay is Drupal7 module for Bank of Georgia's iPay service integration into your Drupal site.

Requirements
==========

iPay is 100% standalone module. It requires no other modules.

Installation
=============

- Download and extract your module in your sites/all/modules/bog_ipay folder.

- Enable it through the administration area (admin/modules) or through drush (drush -y pm-enable bog_ipay).


Usage
==========

- Navigate to /admin/config/ipay/settings, you will see following settings page for iPay module
![Settings page](settings.png "Settings page")
"Service Url" field will be automatically generated for you.
Please fill other required fields and save the settings.

- Module provides full integration with BOG's iPay service. It fires standard drupal hooks for every event (requests from iPay servers) and ANY module is able to hook into that events and implement their custom logic.

Hooks
==========
<pre>
<strong>function</strong> hook_ipay_debt($params)

<strong>Parameters:</strong>
$params - an Array of parameters passed from iPay server. e.g. 'OP' => 'debt', 'USERNAME' => 'someuser' etc.

<strong>Return value:</strong>
According to iPay's specification of debt request, this hook must return an array of following structure:
<code>
array(
  'debt' => $debt_value_according_to_ipay_requirements,
  'info' => array(
    'someparam' => 'somevalue',
    'someparam1' => 'somevalue1'
  ),
);
</code>
</pre>

<pre>
<strong>function</strong> hook_ipay_verify($params)

<strong>Parameters:</strong>
$params - an Array of parameters passed from iPay server. e.g. 'OP' => 'debt', 'USERNAME' => 'someuser' etc.

<strong>Return value:</strong>
Hook must return TRUE, if passed parameters verified fine. Otherwise, it should return an array of following structure:
<code>
array(
  'status_code'    => one_of_defined_status_codes,
  'status_message' => 'custom_status_message'
);
</code>
</pre>

<pre>
<strong>function</strong> hook_ipay_pay($params)

<strong>Parameters:</strong>
$params - an Array of parameters passed from iPay server. e.g. 'OP' => 'debt', 'USERNAME' => 'someuser' etc.

<strong>Return value:</strong>
If payment is successfull, hook must return unique receipt_id, otherwise it should return an array of following structure:
<code>
array(
  'status_code'    => one_of_defined_status_codes,
  'status_message' => 'custom_status_message'
);
</code>
</pre>

Author/maintainer
===================

Original Author and Maintainer:

Giorgi Jibladze
http://github.com/jibla
